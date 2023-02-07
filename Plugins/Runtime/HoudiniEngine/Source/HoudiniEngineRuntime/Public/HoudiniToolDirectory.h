#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "HoudiniToolDirectory.generated.h"

USTRUCT(BlueprintType)
struct FHoudiniToolDirectory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FDirectoryPath Path;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    FString ContentDirID;
    
    HOUDINIENGINERUNTIME_API FHoudiniToolDirectory();
};

