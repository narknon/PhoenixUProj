#pragma once
#include "CoreMinimal.h"
#include "TextureFilterRow.generated.h"

USTRUCT(BlueprintType)
struct FTextureFilterRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MeshName;
    
    CUSTOMIZABLECHARACTER_API FTextureFilterRow();
};

