#pragma once

#include "BaseCObject.hpp"
#include "IDialogInitiable.hpp"
#include "IGeoFig.hpp"
#include "IPhysObject.hpp"
#include "IPrintable.hpp"

namespace lab_4 {

class Figure : public IGeoFig, public IDialogInitiable, public IPhysObject, public IPrintable, public BaseCObject {
};

}  // namespace lab_4
