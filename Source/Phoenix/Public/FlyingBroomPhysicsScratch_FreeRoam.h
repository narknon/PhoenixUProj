#pragma once
#include "CoreMinimal.h"
#include "FlyingBroomPhysicsScratch.h"
#include "FlyingBroomPhysicsScratch_FreeRoam.generated.h"

class UFlyingBroomPhysics_FreeRoam;
class UFlyingBroomStats;

UCLASS(Blueprintable)
class UFlyingBroomPhysicsScratch_FreeRoam : public UFlyingBroomPhysicsScratch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomPhysics_FreeRoam* PhysicsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomStats* StatsData;
    
    UFlyingBroomPhysicsScratch_FreeRoam();
};

