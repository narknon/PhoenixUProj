#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/WorldSubsystem.h"
#include "FlowDynamicRippleRequest.h"
#include "FlowRippleSubsystem.generated.h"

class UFlowRippleSystemSettings;
class UPlayerRenderTarget;
class USceneComponent;
class UTextureRenderTarget2DArray;

UCLASS(Blueprintable)
class FLOW_API UFlowRippleSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2DArray* RenderTargetResource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerRenderTarget* PlayerRenderTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlowRippleSystemSettings* Settings;
    
public:
    UFlowRippleSubsystem();
    UFUNCTION(BlueprintCallable)
    void UnregisterDynamicRippleSource(USceneComponent* Attachment);
    
    UFUNCTION(BlueprintCallable)
    void RemovePersistentRippleSource(USceneComponent* Requester);
    
    UFUNCTION(BlueprintCallable)
    void RegisterDynamicRippleSource(const FFlowDynamicRippleRequest& Request);
    
    UFUNCTION(BlueprintCallable)
    void AddRipple(const FVector& PositionWorld, float Intensity, float Radius, float LifeTime, float ForceOverLifetime);
    
    UFUNCTION(BlueprintCallable)
    void AddPersistentRippleSource(USceneComponent* Requester, float Intensity, float Radius, float OscillationFrequency);
    
};

