#pragma once
#include "CoreMinimal.h"
#include "EBroomEnemyState.h"
#include "Templates/SubclassOf.h"
#include "SpawnedStudent.generated.h"

class AFlyingBroom;
class UFlyingBroomPhysics_Spline;
class UScheduledEntity;
class USplineComponent;

USTRUCT(BlueprintType)
struct FSpawnedStudent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* BroomSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomPhysics_Spline* PhysicsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UScheduledEntity> ScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFlyingBroom> FlyingBroom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EBroomEnemyState::Type> SpawnState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFlyingBroom* SpawnedFlyingBroom;
    
    PHOENIX_API FSpawnedStudent();
};

