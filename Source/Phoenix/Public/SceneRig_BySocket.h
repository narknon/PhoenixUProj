#pragma once
#include "CoreMinimal.h"
#include "SceneRigProvider.h"
#include "SceneRigSocketEntry.h"
#include "SceneRig_BySocket.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRig_BySocket : public USceneRigProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigSocketEntry> SocketEntries;
    
    USceneRig_BySocket();
};

