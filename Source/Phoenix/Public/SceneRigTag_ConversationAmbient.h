#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "PreviewVariableRequest.h"
#include "SceneRigTag_ConversationAmbient.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneRigTag_ConversationAmbient : public UAnimationArchitectTagProvider, public IPreviewVariableRequest {
    GENERATED_BODY()
public:
    USceneRigTag_ConversationAmbient();
    
    // Fix for true pure virtual functions not being implemented
};

