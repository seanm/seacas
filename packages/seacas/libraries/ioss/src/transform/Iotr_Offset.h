// Copyright(C) 1999-2022 National Technology & Engineering Solutions
// of Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with
// NTESS, the U.S. Government retains certain rights in this software.
//
// See packages/seacas/LICENSE for details

#pragma once

#include <Ioss_Transform.h> // for Transform, Factory
#include <stddef.h>
#include <string> // for string
#include <transform/Iotr_Factory.h>

#include "Ioss_VariableType.h"
#include "iotr_export.h"

namespace Ioss {
  class Field;
} // namespace Ioss

namespace Iotr {

  class IOTR_EXPORT Offset_Factory : public Factory
  {
  public:
    static const Offset_Factory *factory();

  private:
    Offset_Factory();
    Ioss::Transform *make(const std::string & /*unused*/) const override;
  };

  class IOTR_EXPORT Offset : public Ioss::Transform
  {
    friend class Offset_Factory;

  public:
    const Ioss::VariableType *output_storage(const Ioss::VariableType *in) const override;
    size_t                    output_count(size_t in) const override;

    void set_property(const std::string &name, int value) override;
    void set_property(const std::string &name, double value) override;

  protected:
    Offset();

    bool internal_execute(const Ioss::Field &field, void *data) override;

  private:
    int    intOffset{0};
    double realOffset{0.0};
  };
} // namespace Iotr
