#pragma once
#include "CoreMinimal.h"
#include "AblFlyToLocationTaskBase.h"
#include "ENpcReactFlyToLocationOption.h"
#include "AblNpcReactFlyToLocation.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcReactFlyToLocation : public UAblFlyToLocationTaskBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENpcReactFlyToLocationOption TargetLocation;
    
public:
    UAblNpcReactFlyToLocation();
};

