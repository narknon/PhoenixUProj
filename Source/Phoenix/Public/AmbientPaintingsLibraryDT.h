#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AmbientPaintingsLibraryDT.generated.h"

class UDataTable;
class UFileMediaSource;
class UTexture2D;

USTRUCT(BlueprintType)
struct FAmbientPaintingsLibraryDT : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFileMediaSource* AtlasMediaSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* AtlasDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Poster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Width;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Count;
    
    PHOENIX_API FAmbientPaintingsLibraryDT();
};

