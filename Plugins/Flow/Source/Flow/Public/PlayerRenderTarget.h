#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayerRenderTarget.generated.h"

class UPlayerRenderTargetCascade;
class UTextureRenderTarget2DArray;

UCLASS(Blueprintable)
class UPlayerRenderTarget : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPlayerRenderTargetCascade*> Cascades;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2DArray* RenderTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2DArray* RenderTargetAux;
    
    UPlayerRenderTarget();
};

