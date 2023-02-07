#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FlyingBroomPhysicsScratch.generated.h"

class UFlyingBroomMovementComponent;

UCLASS(Blueprintable)
class UFlyingBroomPhysicsScratch : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFlyingBroomMovementComponent* MovementComponent;
    
    UFlyingBroomPhysicsScratch();
};

