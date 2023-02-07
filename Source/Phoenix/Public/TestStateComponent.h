#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectStateData.h"
#include "RepairData.h"
#include "TestStateComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UTestStateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectStateData ObjectStateData;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRepairData RepairData;
    
    UTestStateComponent();
};

