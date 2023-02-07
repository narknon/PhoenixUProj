#pragma once
#include "CoreMinimal.h"
#include "ModifyMaterials_TextureOverride.h"
#include "SmartTexture.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FSmartTexture {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* DefaultTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FModifyMaterials_TextureOverride> TextureOverrides;
    
    SCENERIG_API FSmartTexture();
};

