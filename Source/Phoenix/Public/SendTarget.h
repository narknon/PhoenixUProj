#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/TargetPoint.h"
#include "SendTargetHitSignatureDelegate.h"
#include "SendTarget.generated.h"

class AActor;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(Blueprintable)
class ASendTarget : public ATargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SphereComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDetectsCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableWhenHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyHitByTargetingActor;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSendTargetHitSignature OnSendTargetHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> TargetingActors;
    
    ASendTarget(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetSendTargetPriority(uint8 InPriority);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool bInEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetSendTargetPriority() const;
    
    UFUNCTION(BlueprintCallable)
    void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

