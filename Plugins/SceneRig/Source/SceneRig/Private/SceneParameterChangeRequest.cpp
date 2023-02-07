#include "SceneParameterChangeRequest.h"

FSceneParameterChangeRequest::FSceneParameterChangeRequest() {
    this->ChangeType = ESceneParameterChangeRequestType::String;
    this->Bool = false;
    this->float = 0.00f;
    this->Object = NULL;
    this->int = 0;
}

