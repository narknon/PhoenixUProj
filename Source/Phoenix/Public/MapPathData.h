#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MapPathData.generated.h"

class UMapPath;

UCLASS(Blueprintable)
class UMapPathData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapPath*> AllPaths;
    
    UMapPathData();
};

