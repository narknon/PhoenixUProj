#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PersistentGameDataListInfo.h"
#include "PersistentGameDataList.generated.h"

UCLASS(Blueprintable)
class PERSISTENTDATA_API UPersistentGameDataList : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VersionMajor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VersionMinor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPersistentGameDataListInfo Info;
    
    UPersistentGameDataList();
};

