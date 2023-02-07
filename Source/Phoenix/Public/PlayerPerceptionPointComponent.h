#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerPerceptionPointComponent.generated.h"

class APerceptionPoint;
class UAISenseConfig;
class UPlayer_FootfallDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerPerceptionPointComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAISenseConfig*> SensesConfigList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APerceptionPoint* PerceptionPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayer_FootfallDataAsset* FootfallDataAsset;
    
    UPlayerPerceptionPointComponent();
};

