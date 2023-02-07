#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TextureUtil.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class UTextureUtil : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* TargetTexture;
    
public:
    UTextureUtil();
};

