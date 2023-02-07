#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ESimpleUpdatePumpComponentMode.h"
#include "SimpleUpdatePumpComponent.generated.h"

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API USimpleUpdatePumpComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESimpleUpdatePumpComponentMode SimpleUpdatePumpMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuspend;
    
    USimpleUpdatePumpComponent();
};

