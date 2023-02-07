#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AblChannelingBase.h"
#include "Templates/SubclassOf.h"
#include "AblChannelingObjectArchitectConditional.generated.h"

class UAblAbility;
class UObjectArchitectAsset;

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblChannelingObjectArchitectConditional : public UAblChannelingBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BranchTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> BranchAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectArchitectAsset* ObjectArchitectAsset;
    
public:
    UAblChannelingObjectArchitectConditional();
};

