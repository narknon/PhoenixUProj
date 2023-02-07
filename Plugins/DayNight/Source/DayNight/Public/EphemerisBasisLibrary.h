#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EphemerisBasisPerLevel.h"
#include "EphemerisBasisLibrary.generated.h"

class UEphemerisBasis;

UCLASS(Blueprintable)
class DAYNIGHT_API UEphemerisBasisLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEphemerisBasis* DefaultBasis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEphemerisBasisPerLevel> LevelBasis;
    
    UEphemerisBasisLibrary();
};

