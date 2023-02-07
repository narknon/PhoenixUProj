#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "EPerformTaskSplineTypes.h"
#include "SplineCompletedDelegate.h"
#include "SimpleSplineFollowerForAI.generated.h"

class ASimpleSplineFollowerForAI;
class UPathComponent;
class UScheduledEntity;

UCLASS(Blueprintable)
class ASimpleSplineFollowerForAI : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPathComponent* PathComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskSplineTypes SplineType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSprintSplineType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartAtSplineStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo MissionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MissionUID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSplinePoint> SplinePointsFromOtherSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimpleSplineFollowerForAI* OtherSplinePath;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSplineCompleted OnSplineCompleted;
    
    ASimpleSplineFollowerForAI();
private:
    UFUNCTION(BlueprintCallable)
    void StartAIMovementOnSpline(UScheduledEntity* InScheduledEntity, int32 ActivityTypeBits);
    
    UFUNCTION(BlueprintCallable)
    void OnFleshLoadComplete(AActor* FleshActor);
    
    UFUNCTION(BlueprintCallable)
    void MoveOnSplineFleshLoad(AActor* FleshActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void CreateSplineFromGivenPoints();
    
};

