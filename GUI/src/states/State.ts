import Portion from './Portion';
import MakingPortion from './MakingPortion';
import { MarbleColor } from './MarbleColor';

export interface State {
    usablePortions: Portion[];
    discardedPortions: Portion[];
    makingPortions: MakingPortion[];
    savingMarbles: MarbleColor[];
}
