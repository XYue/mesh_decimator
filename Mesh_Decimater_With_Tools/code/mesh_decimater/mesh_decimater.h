#ifndef MESH_DECIMATER_H
#define MESH_DECIMATER_H

#include "dec_options.h"

template <typename Mesh, typename DecimaterType>
bool decimate(const std::string &_ifname,
         const std::string &_ofname,
         DecOptions        &_opt,
         int gverbose);

#include "mesh_decimater.template"

#endif // MESH_DECIMATER_H