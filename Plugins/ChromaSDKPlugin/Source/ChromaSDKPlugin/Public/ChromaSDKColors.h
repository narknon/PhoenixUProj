#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChromaSDKColors.generated.h"

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKColors {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearColor> Colors;
    
    FChromaSDKColors();
};

