#include "SceneParameterChangeRequest.h"

FSceneParameterChangeRequest::FSceneParameterChangeRequest() {
    this->ChangeType = ESceneParameterChangeRequestType::String;
    this->Bool = false;
    this->Float = 0.00f;
    this->Object = NULL;
    this->Int = 0;
}

