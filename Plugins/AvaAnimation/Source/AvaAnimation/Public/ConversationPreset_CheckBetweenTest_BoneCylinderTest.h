#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_CheckBetweenTest.h"
#include "ConversationPreset_CheckBetweenTest_BoneCylinderTest.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_CheckBetweenTest_BoneCylinderTest : public UConversationPreset_CheckBetweenTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TuckInMultipler;
    
    UConversationPreset_CheckBetweenTest_BoneCylinderTest();
};

