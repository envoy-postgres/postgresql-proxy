#include "extensions/filters/network/postgresql_proxy/postgresql_filter.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace PostgreSQLProxy {

PostgreSQLFilterConfig::PostgreSQLFilterConfig(const std::string& stat_prefix, Stats::Scope& scope)
    : stat_prefix_{stat_prefix}, scope_{scope}, stats_{generateStats(stat_prefix, scope)} {}

PostgreSQLFilter::PostgreSQLFilter(PostgreSQLFilterConfigSharedPtr config) : config_{config} {}

// Network::ReadFilter
Network::FilterStatus PostgreSQLFilter::onData(Buffer::Instance&, bool) {
  return Network::FilterStatus::Continue;
}
Network::FilterStatus PostgreSQLFilter::onNewConnection() {
  return Network::FilterStatus::Continue;
}
void PostgreSQLFilter::initializeReadFilterCallbacks(Network::ReadFilterCallbacks&) {}

// Network::WriteFilter
Network::FilterStatus PostgreSQLFilter::onWrite(Buffer::Instance&, bool) {
  return Network::FilterStatus::Continue;
}

} // namespace PostgreSQLProxy
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
