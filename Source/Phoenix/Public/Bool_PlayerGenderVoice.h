#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "EGenderVoice.h"
#include "Bool_PlayerGenderVoice.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UBool_PlayerGenderVoice : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenderVoice Voice;
    
    UBool_PlayerGenderVoice();
};

