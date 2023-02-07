#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FlowWaveSubsystem.generated.h"

class UFlowWaveSystemSettings;
class ULakeComponent;
class UTextureRenderTarget2DArray;

UCLASS(Blueprintable)
class UFlowWaveSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULakeComponent*> RegisteredLakes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2DArray* RenderTargetResourcesWaveDisps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2DArray* RenderTargetResourceWaveFoam;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFlowWaveSystemSettings* Settings;
    
public:
    UFlowWaveSubsystem();
};

