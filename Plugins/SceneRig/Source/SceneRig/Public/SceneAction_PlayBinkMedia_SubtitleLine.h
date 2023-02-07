#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SceneAction_PlayBinkMedia_SubtitleLine.generated.h"

USTRUCT(BlueprintType)
struct FSceneAction_PlayBinkMedia_SubtitleLine : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndTime;
    
    SCENERIG_API FSceneAction_PlayBinkMedia_SubtitleLine();
};

