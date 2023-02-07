#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PlayerRenderTargetSubsystem.generated.h"

class UMaterialParameterCollection;
class UNiagaraParameterCollection;
class UPlayerRenderTarget;

UCLASS(Blueprintable)
class UPlayerRenderTargetSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPlayerRenderTarget*> RenderTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* RenderTargetMaterialParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* NiagaraParameterCollection;
    
public:
    UPlayerRenderTargetSubsystem();
};

