#pragma once
#include "CoreMinimal.h"
#include "ChromaSDKColors.h"
#include "ChromaSDKColorFrame2D.generated.h"

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKColorFrame2D {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FChromaSDKColors> Colors;
    
    FChromaSDKColorFrame2D();
};

