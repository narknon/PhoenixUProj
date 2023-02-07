#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "CameraStickLastMovedDelegateDelegate.h"
#include "CameraStickTimerExpiredDelegate.h"
#include "TargetChangedDelegateDelegate.h"
#include "TargetLostDelegateDelegate.h"
#include "TargetSightedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "CognitionComponent.generated.h"

class AActor;
class UAISense;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class COGNITION_API UCognitionComponent : public UAIPerceptionComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeOutCameraStickMoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetSightedDelegate TargetSightedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetChangedDelegate TargetChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetLostDelegate TargetLostDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraStickLastMovedDelegate CameraStickLastMovedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraStickTimerExpired CameraStickTimerExpiredDelegate;
    
    UCognitionComponent();
    UFUNCTION(BlueprintCallable)
    void TimerExpired();
    
    UFUNCTION(BlueprintCallable)
    void SetRightStickMoving(bool bInFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetMovementFocusDirection(const FVector& WorldDirection);
    
    UFUNCTION(BlueprintCallable)
    void SetLeftStickMoving(bool bInFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetIsLocked(bool bInFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetCameraLastMovedStick(bool InFlag);
    
    UFUNCTION(BlueprintCallable)
    bool IsRightStickMoving();
    
    UFUNCTION(BlueprintCallable)
    bool IsLocked();
    
    UFUNCTION(BlueprintCallable)
    bool IsLeftStickMoving();
    
    UFUNCTION(BlueprintCallable)
    bool IsCameraLastMovedStick();
    
    UFUNCTION(BlueprintCallable)
    FVector GetMovementFocusDirection();
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetCameraFlickDirection();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetBestTarget(TSubclassOf<UAISense> SenseImplementation);
    
    UFUNCTION(BlueprintCallable)
    void DEBUG_CycleDebug();
    
    UFUNCTION(BlueprintCallable)
    void DEBUG_ByIndex(int32 InIndex);
    
};

