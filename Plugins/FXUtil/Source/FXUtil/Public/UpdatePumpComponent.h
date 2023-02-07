#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EUpdatePumpComponentMode.h"
#include "UpdatePumpComponent.generated.h"

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FXUTIL_API UUpdatePumpComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUpdatePumpComponentMode UpdatePumpMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuspend;
    
    UUpdatePumpComponent();
};

