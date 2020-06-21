# FactorioFactoryCalculator

This software helps you to estimate how many factories is required to create each item with required speed.

## Demo
TBD

## Feature
* Shows a tree of creation in a tree view.
* Estimates how many factories is required to create an item by clicking an item in the tree.
* Speed / rate of the generated sub-items is also shown to help you decide what kind of belt is required.
* Speed / rate of generated target item which you want to calculate for can be changed by editing the number and push "set" button.
* Data for generating item tree is CSV. You can modify the data to fit to various mods.
* Number of genarated item can be decimal. This enables calculation for items generated with probability; such as 80%.
* Factory types to be used for calculation can be selected. The factory data is stored as CSV, so you can edit them for your mods.

## Requirement
Intel / AMD based PC, Windows 10. No runtimes required.

## Specifications / Limits
* Does not generate infinite-loop tree. If there is a loop, it will not show the sub-item for the second loop. This means, It will show only first loop of creations for an item such as U-235.
* CSV file name of the item and the factory is fixed to item.csv and factory.csv. They are loaded from a folder which you choose by a button.

## CSV file formats
* CSV files should be written in UTF-16 LE.
* The first line is always recognized as an header; it will be ignored.
* A line starting with // will be skipped.
* An empty line will be skipped.
* Each item is separated only by comma (,). Heading spaces and trailing spaces of each item is trimmed.

### Item.csv format
NAME, NUM, TIME, FACTORY_NUM, FACTORY_1, FACTORY_2, ... , MATERIAL_1, MATERIAL_1_NUM, MATERIAL_2, MATERIAL_2_NUM, ...
* NAME: Name of the item. A space between letters is kept as it is. Ex. Quantum Phenomenon Data
* NUM: Number of items created in one time. It can be decimal, such as 0.8, in case they are generated with probability.
* TIME: Lenght of time required for the item to be created. It can be decimal.
* FACTORY_NUM: Number of factory types which can create the item. Should be integer.
* FACTORY_N: Name of the factory which can create the item. If the FACTORY_NUM is 3 for example, you should list 3 name of the factory.
* MATERIAL_N: Name of the required material for creation of the item. The number of the types of the material is guessed from number of columns in the line.
* MATERIAL_N_NUM: Number of the required material for the creation. The number can be decimal, for in case of liqueds and gases.

### Factory.csv format
NAME, SPEED
* NAME: Name of the factory. A space between letters is kept as it is. Ex. Super computer
* SPEED: Speed gain of the factory. It can be decimal.


## Install
Uncompress the files into any folder you want. By double-clicking FactorioFactoryCalculator.exe, you can start the software. The software does not have installer at this moment.

## Licence
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
