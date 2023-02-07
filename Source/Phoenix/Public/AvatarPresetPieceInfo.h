#pragma once
#include "CoreMinimal.h"
#include "AvatarPresetPieceInfo.generated.h"

USTRUCT(BlueprintType)
struct FAvatarPresetPieceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MeshName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMeshSettable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Parameters;
    
    PHOENIX_API FAvatarPresetPieceInfo();
};

