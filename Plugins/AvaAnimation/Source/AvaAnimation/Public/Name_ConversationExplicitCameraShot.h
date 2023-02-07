#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitCameraShotReference.h"
#include "NameProvider.h"
#include "Name_ConversationExplicitCameraShot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UName_ConversationExplicitCameraShot : public UNameProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationExplicitCameraShotReference Reference;
    
    UName_ConversationExplicitCameraShot();
};

