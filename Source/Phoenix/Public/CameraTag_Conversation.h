#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "PreviewVariableRequest.h"
#include "CameraTag_Conversation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraTag_Conversation : public UAnimationArchitectTagProvider, public IPreviewVariableRequest {
    GENERATED_BODY()
public:
    UCameraTag_Conversation();
    
    // Fix for true pure virtual functions not being implemented
};

