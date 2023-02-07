#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChromaSDKColorFrame1D.generated.h"

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKColorFrame1D {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearColor> Colors;
    
    FChromaSDKColorFrame1D();
};

