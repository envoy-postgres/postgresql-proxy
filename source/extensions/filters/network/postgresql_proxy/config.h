#pragma once

#include "extensions/filters/network/common/factory_base.h"
#include "extensions/filters/network/postgresql_proxy/postgresql_filter.h"

// TODO(dio): Move this to qpi directory when merging to upstream.
#include "source/extensions/filters/network/postgresql_proxy/config.pb.h"
#include "source/extensions/filters/network/postgresql_proxy/config.pb.validate.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace PostgreSQLProxy {

/**
 * Config registration for the PostgreSQL proxy filter.
 */
class PostgreSQLConfigFactory
    : public Common::FactoryBase<
          envoy::config::filter::network::postgresql_proxy::v1alpha1::PostgreSQLProxy> {
public:
  // TODO(dio): Put this filter name in well_known_names.h.
  PostgreSQLConfigFactory() : FactoryBase{"envoy.filters.network.postgresql_proxy"} {}

private:
  Network::FilterFactoryCb createFilterFactoryFromProtoTyped(
      const envoy::config::filter::network::postgresql_proxy::v1alpha1::PostgreSQLProxy&
          proto_config,
      Server::Configuration::FactoryContext& context) override;
};

} // namespace PostgreSQLProxy
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
