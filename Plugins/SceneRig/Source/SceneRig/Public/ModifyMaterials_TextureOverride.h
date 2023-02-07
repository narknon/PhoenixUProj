#pragma once
#include "CoreMinimal.h"
#include "ModifyMaterials_TextureOverride.generated.h"

class UFXRule;
class UTexture2D;

USTRUCT(BlueprintType)
struct FModifyMaterials_TextureOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXRule*> Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    SCENERIG_API FModifyMaterials_TextureOverride();
};

