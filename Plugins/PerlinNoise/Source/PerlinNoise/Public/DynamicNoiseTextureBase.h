#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DynamicNoiseTextureBase.generated.h"

class UTexture2D;

UCLASS(Abstract, Blueprintable)
class PERLINNOISE_API UDynamicNoiseTextureBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Width;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateInterval;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float NextUpdate;
    
public:
    UDynamicNoiseTextureBase();
    UFUNCTION(BlueprintCallable)
    UTexture2D* GetDynamicTexture();
    
};

