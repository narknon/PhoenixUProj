#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "BehaviorTree/BTDecorator.h"
#include "OdcFlags.h"
#include "BTDecorator_CreatureCheckNavmeshAreaFlag.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_CreatureCheckNavmeshAreaFlag : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCreaturePreferredAreaFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcFlags CustomAreaFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue ParameterizedHorizontalQueryRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIDataProviderFloatValue ParameterizedVerticalQueryRadius;
    
    UBTDecorator_CreatureCheckNavmeshAreaFlag();
};

