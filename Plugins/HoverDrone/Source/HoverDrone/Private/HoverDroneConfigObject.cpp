#include "HoverDroneConfigObject.h"
#include "HoverDroneController.h"

UHoverDroneConfigObject::UHoverDroneConfigObject() {
    this->m_HoverDroneControllerClass = AHoverDroneController::StaticClass();
}

