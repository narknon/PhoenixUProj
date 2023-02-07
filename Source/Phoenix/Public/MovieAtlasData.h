#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MovieAtlasData.generated.h"

USTRUCT(BlueprintType)
struct FMovieAtlasData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Width;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Height;
    
    PHOENIX_API FMovieAtlasData();
};

