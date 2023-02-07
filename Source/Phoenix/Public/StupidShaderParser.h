#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StupidShaderParser.generated.h"

UCLASS(Blueprintable)
class UStupidShaderParser : public UDataAsset {
    GENERATED_BODY()
public:
    UStupidShaderParser();
    UFUNCTION(BlueprintCallable)
    void WriteCSV();
    
    UFUNCTION(BlueprintCallable)
    void Import();
    
};

