#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialSaver.generated.h"

class UMaterialInterface;
class UMeshComponent;

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXMaterialSaver {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> OriginalMaterials;
    
public:
    FSkinFXMaterialSaver();
};

