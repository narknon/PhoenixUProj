#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "AblTaskCondition_OppugnoProxy.generated.h"

class AWorldObject;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UAblTaskCondition_OppugnoProxy : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AWorldObject> OppugnoProxy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProxyOppugnoWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DuelTechniqueEventTag;
    
    UAblTaskCondition_OppugnoProxy();
};

