#pragma once
#include "CoreMinimal.h"
#include "ConversationCameraRegistrationReference.h"
#include "NameProvider.h"
#include "Name_ConversationCameraRegistration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UName_ConversationCameraRegistration : public UNameProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationCameraRegistrationReference Camera;
    
    UName_ConversationCameraRegistration();
};

