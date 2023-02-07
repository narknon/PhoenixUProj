#pragma once
#include "CoreMinimal.h"
#include "AkCallbackInfo.h"
#include "AkSegmentInfo.h"
#include "EAkCallbackType.h"
#include "AkMusicSyncCallbackInfo.generated.h"

UCLASS(Blueprintable)
class UAkMusicSyncCallbackInfo : public UAkCallbackInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayingID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAkSegmentInfo SegmentInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAkCallbackType MusicSyncType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UserCueName;
    
    UAkMusicSyncCallbackInfo();
};

