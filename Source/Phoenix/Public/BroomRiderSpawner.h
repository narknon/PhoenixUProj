#pragma once
#include "CoreMinimal.h"
#include "EHoboType.h"
#include "EGenderEnum.h"
#include "GameFramework/Actor.h"
#include "EBroomEnemyState.h"
#include "HouseIds.h"
#include "SpawnedStudent.h"
#include "Templates/SubclassOf.h"
#include "BroomRiderSpawner.generated.h"

class AEnemyBroomRider_AiController;
class AFlyingBroom;
class UFlyingBroomPhysics_Spline;
class UScheduledEntity;
class USplineComponent;

UCLASS(Abstract, Blueprintable)
class ABroomRiderSpawner : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FScheduledEntityLoaded, const UScheduledEntity*, ScheduledEntity, const AFlyingBroom*, FlyingBroom, const AEnemyBroomRider_AiController*, BroomRiderAIController);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* BroomSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomPhysics_Spline* FlyingBroomPhysics;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScheduledEntityLoaded OnScheduledEntityLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AFlyingBroom*> SpawnedBrooms;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnedStudent> SpawnedBroomStudents;
    
public:
    ABroomRiderSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool RequestBroomNPC(const EHoboType HoboType, const TEnumAsByte<HouseIds> InHouse, const EGenderEnum InGender, const TArray<FString>& ValidVoiceIDs, TSubclassOf<AFlyingBroom> FlyingBroom, TEnumAsByte<EBroomEnemyState::Type> StudentAISpawnState, float MaxSpeed);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnFleshLoadComplete(AActor* ScheduledEntityActor);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DestroyAllRiders();
    
};

