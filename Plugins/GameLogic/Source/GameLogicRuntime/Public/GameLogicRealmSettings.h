#pragma once
#include "CoreMinimal.h"
#include "EGameLogicEditorPanel.h"
#include "EGameLogicElementSize.h"
#include "EGameLogicRealmPrivacy.h"
#include "GameLogicRealmSettings.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGameLogicRealmSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameLogicRealmPrivacy RealmPrivacy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ElementPanelBitFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ElementPanelMinimized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameLogicEditorPanel, EGameLogicElementSize> ElementSize;
    
    FGameLogicRealmSettings();
};

