#pragma once
#include "CoreMinimal.h"
#include "MIDScalarParameter.h"
#include "MIDTextureParameter.h"
#include "MIDVectorParameter.h"
#include "MIDParameters.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMIDParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMIDScalarParameter> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMIDVectorParameter> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMIDTextureParameter> Textures;
    
    FMIDParameters();
};

