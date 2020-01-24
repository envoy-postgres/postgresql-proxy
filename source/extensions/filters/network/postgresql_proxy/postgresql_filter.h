#pragma once

#include "envoy/network/filter.h"
#include "envoy/stats/scope.h"
#include "envoy/stats/stats.h"
#include "envoy/stats/stats_macros.h"

#include "common/buffer/buffer_impl.h"
#include "common/common/logger.h"

#include "extensions/filters/network/postgresql_proxy/postgresql_decoder.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace PostgreSQLProxy {

/**
 * All PostgreSQL proxy stats. @see stats_macros.h
 */
#define ALL_POSTGRESQL_PROXY_STATS(COUNTER)   \
  COUNTER(sessions)                           \
  COUNTER(errors)                             \
  COUNTER(statements)                         \
  COUNTER(statements_insert)                  \
  COUNTER(statements_delete)                  \
  COUNTER(statements_update)                  \
  COUNTER(statements_select)                  \
  COUNTER(statements_other)                   \
  COUNTER(transactions)                       \
  COUNTER(transactions_commit)                \
  COUNTER(transactions_rollback)              \
  COUNTER(warnings)

/**
 * Struct definition for all PostgreSQL proxy stats. @see stats_macros.h
 */
struct PostgreSQLProxyStats {
  ALL_POSTGRESQL_PROXY_STATS(GENERATE_COUNTER_STRUCT)
};

/**
 * Configuration for the PostgreSQL proxy filter.
 */
class PostgreSQLFilterConfig {
public:
  PostgreSQLFilterConfig(const std::string& stat_prefix, Stats::Scope& scope);

  const std::string stat_prefix_;
  Stats::Scope& scope_;
  PostgreSQLProxyStats stats_;

private:
  PostgreSQLProxyStats generateStats(const std::string& prefix, Stats::Scope& scope) {
    return PostgreSQLProxyStats{ALL_POSTGRESQL_PROXY_STATS(POOL_COUNTER_PREFIX(scope, prefix))};
  }
};

using PostgreSQLFilterConfigSharedPtr = std::shared_ptr<PostgreSQLFilterConfig>;

class PostgreSQLFilter : public Network::Filter, DecoderCallbacks, Logger::Loggable<Logger::Id::filter> {
public:
  PostgreSQLFilter(PostgreSQLFilterConfigSharedPtr config);
  ~PostgreSQLFilter() override = default;

  // Network::ReadFilter
  Network::FilterStatus onData(Buffer::Instance& data, bool end_stream) override;
  Network::FilterStatus onNewConnection() override;
  void initializeReadFilterCallbacks(Network::ReadFilterCallbacks& callbacks) override;

  // Network::WriteFilter
  Network::FilterStatus onWrite(Buffer::Instance& data, bool end_stream) override;

  // PostgreSQLProxy::DecoderCallback
  void incErrors() override;
  void incSessions() override;
  void incStatements() override;
  void incStatementsDelete() override;
  void incStatementsInsert() override;
  void incStatementsOther() override;
  void incStatementsSelect() override;
  void incStatementsUpdate() override;
  void incTransactions() override;
  void incTransactionsCommit() override;
  void incTransactionsRollback() override;
  void incWarnings() override;

  void doDecode(Buffer::Instance& data);
  DecoderPtr createDecoder(DecoderCallbacks& callbacks);
private:
  Network::ReadFilterCallbacks* read_callbacks_{};
  PostgreSQLFilterConfigSharedPtr config_;
  Buffer::OwnedImpl frontend_buffer_;
  Buffer::OwnedImpl backend_buffer_;
  std::unique_ptr<Decoder> decoder_;
};

} // namespace PostgreSQLProxy
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
